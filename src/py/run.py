import pygame as pg
from game import Game


pg.init()

BG_COLOR = (187, 173, 160)
WINDOW_WIDTH = 500
WINDOW_HEIGHT = 500
BORDER_SIZE = WINDOW_WIDTH // 6
TOP_OFFSET = BORDER_SIZE
LEFT_OFFSET = WINDOW_WIDTH // 5
font = pg.font.SysFont('timesnewroman', 32)


colors = {
    -2:     (119, 110, 101),
    -1:     (249, 246, 242),
    0:      (205,193,180),
    2:      (238,228,218),
    4:      (237,224,200),
    8:      (242,177,121),
    16:     (245,149,99),
    32:     (246,124,95),
    64:     (246,94,59),
    128:    (237,207,114),
    256:    (237,207,114),
    512:    (237,207,114),
    1024:   (237,207,114),
    2048:   (237,207,114),
    4096:   (237,207,114),
    8192:   (237,207,114),
    16384:  (237,207,114),
    32768:  (237,207,114),
    65536:  (237,207,114),
}

class Block(pg.sprite.Sprite):
    """Class for generating block on board given position and value"""
    def __init__(self, val: int, x: int, y: int):
        super().__init__()

        color = colors[val] if val in colors else colors[0]
        textColor = colors[-1] if val > 4 else colors[-2] if val else colors[0]
        
        self.image = font.render(str(val), True, textColor, color)

        self.rect = self.image.get_rect()
        self.rect.x, self.rect.y = x, y

def gen_top(score):
    return

size = (WINDOW_WIDTH, WINDOW_HEIGHT)
screen = pg.display.set_mode(size)
pg.display.set_caption("2048")
exit = True

clock = pg.time.Clock()

def gameToGroup(mat: list[list[int]]):
    """Returns list of sprites given game array"""
    a, b, all_sprites_list = len(mat), len(mat[0]), pg.sprite.Group()
    for x in range(a):
        for y in range(b):
            z = Block(mat[y][x], LEFT_OFFSET + x * BORDER_SIZE, TOP_OFFSET + y * BORDER_SIZE)
            all_sprites_list.add(z)
    return all_sprites_list



game = Game()
all_sprites_list = gameToGroup(game.board)

while not game.end:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            game.end = True
        elif event.type == pg.KEYDOWN and event.key == pg.K_UP:
            game.move(2)
        elif event.type == pg.KEYDOWN and event.key == pg.K_DOWN:
            game.move(3)
        elif event.type == pg.KEYDOWN and event.key == pg.K_LEFT:
            game.move(0)
        elif event.type == pg.KEYDOWN and event.key == pg.K_RIGHT:
            game.move(1)

    all_sprites_list = gameToGroup(game.board)
    all_sprites_list.update()
    screen.fill(BG_COLOR)
    all_sprites_list.draw(screen)
    pg.display.flip()
    clock.tick(60)

pg.quit()
