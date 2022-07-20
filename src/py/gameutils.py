import pygame as pg

BG_COLOR = (187, 173, 160)
WINDOW_WIDTH = 500
WINDOW_HEIGHT = 500
BORDER_SIZE = WINDOW_WIDTH // 6
TOP_OFFSET = BORDER_SIZE
LEFT_OFFSET = WINDOW_WIDTH // 5
size = (WINDOW_WIDTH, WINDOW_HEIGHT)
font = pg.font.SysFont("timesnewroman", 32)


colors = {
    -2: (119, 110, 101),
    -1: (249, 246, 242),
    0: (205, 193, 180),
    2: (238, 228, 218),
    4: (237, 224, 200),
    8: (242, 177, 121),
    16: (245, 149, 99),
    32: (246, 124, 95),
    64: (246, 94, 59),
    128: (237, 207, 114),
    256: (237, 204, 97),
    512: (237, 200, 80),
    1024: (237, 197, 63),
    2048: (237, 194, 46),
    4096: (237, 207, 114),
    8192: (237, 207, 114),
    16384: (237, 207, 114),
    32768: (237, 207, 114),
    65536: (237, 207, 114),
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


def isKey(event, key):
    """Returns true if specified key is pressed"""
    return True if event.type == pg.KEYDOWN and event.key == key else False


def gameToGroup(mat: list[list[int]]):
    """Returns list of sprites given game array"""
    a, b, all_sprites_list = len(mat), len(mat[0]), pg.sprite.Group()
    for x in range(a):
        for y in range(b):
            z = Block(
                mat[y][x], LEFT_OFFSET + x * BORDER_SIZE, TOP_OFFSET + y * BORDER_SIZE
            )
            all_sprites_list.add(z)
    return all_sprites_list