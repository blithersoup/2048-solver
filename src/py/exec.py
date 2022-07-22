import asyncio

import pygame as pg

pg.init()

from gameimplementation import Game
from loadlibrary import lib
from gameutils import *

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
                game.mode = "beam"
            elif isKey(event, pg.K_3):
                game.mode = "montecarlo"
            elif isKey(event, pg.K_4):
                game.mode = "minimax"

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
                    game.move(0)
                elif isKey(event, pg.K_RIGHT):
                    game.move(1)
                elif isKey(event, pg.K_UP):
                    game.move(2)
                elif isKey(event, pg.K_DOWN):
                    game.move(3)

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
            pass
        elif game.mode == "montecarlo":
            pass
        elif game.mode == "minimax":
            pass
        await asyncio.sleep(game.sleep_time)


loop = asyncio.get_event_loop()
loop.create_task(gameloop())
loop.create_task(autoloop())
loop.run_forever()

pg.quit()
