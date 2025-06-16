from PIL import Image
img = Image.open("spp500.png")
img.resize((800, 800), Image.NEAREST).save("spp500-upscaled.png")