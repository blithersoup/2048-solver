import asyncio
from functools import reduce

import pygame as pg

pg.init()

from gameimplementation import Game
from gameutils import *

import solvera
from cppyy.gbl import hello

screen = pg.display.set_mode(size)
pg.display.set_caption("2048")
exit = True

clock = pg.time.Clock()

game = Game()
all_sprites_list = gameToGroup(game.board)


async def gameloop():
    while not game.end:
        for event in pg.event.get():
            # exit loop
            if event.type == pg.QUIT:
                game.end = True

            # mode switch
            if isKey(event, pg.K_1):
                game.mode = "player"
            elif isKey(event, pg.K_2):
                game.mode = "minimax"
            elif isKey(event, pg.K_3):
                game.mode = "beam"
            elif isKey(event, pg.K_4):
                game.mode = "montecarlo"
            

            # speed change
            if isKey(event, pg.K_5):
                if game.sleep_time > 0.05:
                    game.sleep_time -= 0.05
            elif isKey(event, pg.K_6):
                if game.sleep_time < 2:
                    game.sleep_time += 0.05

            # player move handling
            if game.mode == "player":
                if isKey(event, pg.K_LEFT):
                    hello.left(game.board)
                    game.addnum()
                    game.end = hello.isEnd(game.board)
                elif isKey(event, pg.K_RIGHT):
                    hello.right(game.board)
                    game.addnum()
                    game.end = hello.isEnd(game.board)
                elif isKey(event, pg.K_UP):
                    hello.up(game.board)
                    game.addnum()
                    game.end = hello.isEnd(game.board)
                elif isKey(event, pg.K_DOWN):
                    hello.down(game.board)
                    game.addnum()
                    game.end = hello.isEnd(game.board)
                


        # rendering screen
        all_sprites_list = gameToGroup(game.board)
        all_sprites_list.update()
        screen.fill(BG_COLOR)
        all_sprites_list.draw(screen)
        pg.display.flip()
        await asyncio.sleep(0.06)

    # breaks event loop when game is over
    asyncio.get_event_loop().stop()


async def autoloop():
    # will stop when event loop breaks
    while True:
        if game.mode == "beam":
            hello.beam_result(game.board) 
            game.addnum()
            game.end = hello.isEnd(game.board)
        elif game.mode == "montecarlo":
            pass
        elif game.mode == "minimax":
            hello.minimax_result(game.board) 
            game.addnum()
            game.end = hello.isEnd(game.board)
        await asyncio.sleep(game.sleep_time)


loop = asyncio.get_event_loop()
loop.create_task(gameloop())
loop.create_task(autoloop())
loop.run_forever()

pg.quit()
