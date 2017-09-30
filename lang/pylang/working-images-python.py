from PIL import Image

filename = "/home/bliu/Pictures/ttt/IMG_6455.JPG"
filename2 = "/home/bliu/Pictures/ttt/IMG_6454.JPG"
def rotate(filename):
    with Image.open(filename) as image:
        width, height = image.size
        print width, height
        image.rotate(180)
        image.save("rotated.JPG")

def cropping(filename):
    try:
        img = Image.open(filename)
        width, height = img.size

        area = (0, 0, width/2, height/2)
        img = img.crop(area)

        img.save("cropped.JPG")
    except IOError:
        pass

def resize_pic(filename):
    try:
        img = Image.open(filename)
        width, height = img.size

        img = img.resize((width/2, height/2))

        img.save("resized.JPG")
    except IOError:
        pass

def paste(filename, filename2):
    try:
        img = Image.open(filename)
        img2 = Image.open(filename2)
        img.paste(img2, (1000, 1000))

        img.save("paste.JPG")
    except IOError:
        pass

def histogram(filename):
    try:
        img = Image.open(filename)
        print img.histogram()
    except IOError:
        pass

def transpose(filename):
    try:
        img = Image.open(filename)
        transposed_img = img.transpose(Image.FLIP_LEFT_RIGHT)

        transposed_img.save("transposed.JPG")
    except IOError:
        pass

def split(filename):
    try:
        img = Image.open(filename)
        print img.split()
    except IOError:
        pass

def tobitmap(filename):
    try:
        img = Image.open(filename)
        print img.mode

        print img.tobitmap()
        print type(img.tobitmap())
    except IOError:
        pass

def thumbnail(filename):
    try:
        img = Image.open(filename)
        img.thumbnail((200, 200))

        img.save("thumb.JPG")
    except IOError:
        pass

thumbnail(filename2)
