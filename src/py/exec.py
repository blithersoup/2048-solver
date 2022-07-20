import pygame as pg
pg.init()

from gameimplementation import Game
from loadlib import lib
from gameutils import *

screen = pg.display.set_mode(size)
pg.display.set_caption("2048")
exit = True

clock = pg.time.Clock()

game = Game()
all_sprites_list = gameToGroup(game.board)
mode = "player"

while not game.end:
    # input control
    for event in pg.event.get():
        # exit loop
        if event.type == pg.QUIT:
            game.end = True

        # mode switch
        if isKey(event, pg.K_1):
            mode = "player"
        elif isKey(event, pg.K_2):
            mode = "beam"
        elif isKey(event, pg.K_3):
            mode = "montecarlo"
        elif isKey(event, pg.K_4):
            mode = "minimax"

        # player move handling
        if mode == "player":
            if isKey(event, pg.K_UP):
                game.move(2)
            elif isKey(event, pg.K_DOWN):
                game.move(3)
            elif isKey(event, pg.K_LEFT):
                game.move(0)
            elif isKey(event, pg.K_RIGHT):
                game.move(1)

    if mode == "beam":
        pass
    elif mode == "montecarlo":
        pass
    elif mode == "minimax":
        pass

    # rendering screen
    all_sprites_list = gameToGroup(game.board)
    all_sprites_list.update()
    screen.fill(BG_COLOR)
    all_sprites_list.draw(screen)
    pg.display.flip()
    clock.tick(60)

pg.quit()
