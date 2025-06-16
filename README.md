# Ray Tracer In a Weekend

![](images/heroRender.png)

## Material ShowCase

### Simple Materials

| Solid | Diffuse | Normal |
|-------|---------|--------|
| ![](images/solid/render.png) | ![](images/diffuse/render.png) | ![](images/normal/render.png) |

### Metal

Metal, as a material consists of two major properties: reflectance and color of the metal itself. The reflectance can also have a "fuzz" factor just like in real life. Below you can see a progression of fuzz factor from shiny metal ball to almost diffuse metal ball ( acts just like a diffuse spehre m aterial )
<br>

| Metal ( 0 fuzz ) | Metal ( 0.5 fuzz ) | Metal ( 1 fuzz ) |
|-------|---------|--------|
| ![](images/metal/fuzz0.png) | ![](images/metal/fuzz0.5.png) | ![](images/metal/fuzz1.png) |

<div align="center">
<table>
    <thead>
    <tr>
      <th width="50%">Description</th>
      <th width="50%">Metal Reflecting Into Metal</th>
    </tr>
  </thead>
  <tbody>
  <tr>
    <td width="50%">
      Here, we can see that we have placed two metal spheres beside each other, with fuzz factor set to 0. Adhering to the laws of physics, we can see the spheres reflecting into each other
    </td>
    <td width="50%">
      <img src="images/metal/metalIntoMetalreflection.png" width="100%">
    </td>
  </tr>
    </tbody>
</table>
</div>

###  Dielectric

Dielectrics are materials that are weka conductors of electricty, like wool, water, sand, air etc.. Here we tried to simulate "glass" and that too implemeintg reflection, refraction and total internal reflection

| Dielectric | Dielectric inside Dielectric |
|-------|---------|
| ![](images/dielectric/dielctric.png) | ![](images/dielectric/dielectricInsideDielectricReRender.png) |

### Bounced Reflections

Here you can see that there is a white sphere in the scene. It get's a slightly tinted color due to the rays bouncing into the sky and ground

<div align="center">
<table>
    <thead>
    <tr>
      <th width="50%">Descrpiptnoe</th>
      <th width="50%">You can see the bluish tint at the top due to sky and a greenish tint at the bottom of the pshere due to the ground</th>
    </tr>
  </thead>
  <tbody>
  <tr>
    <td width="50%">
      dsdfsdf
    </td>
    <td width="50%">
      <img src="images/BouncedReflections/render.png" width="100%">
    </td>
  </tr>
    </tbody>
</table>
</div>

### Anti-Aliasing

Anti-Aliasing is the smoothning of jagged stairs that appear in images. In real life images are continuous, so we also implement that by averaging the pixel values, so we get a smooth gradient for pixels

| SPP 1 | SPP 100 | SPP 500 |
|-------|---------|--------|
| ![](images/antiAliasing/spp1-upscaled.png) | ![](images/antiAliasing/spp100-upscaled.png) | ![](images/antiAliasing/spp500-upscaled.png) |

### De-focus Angle

Defocus Angle, When we have depth of field ~ we techincially divide the iamge into two major areas: one sharp and other blurred. This factor helps us to control how much should we blur the "blurry" areas

| defocus Angle 0.0 | defocus Angle 0.5 | defocus Angle 1.0 |
|-------|---------|--------|
| ![](images/defocusAngle/0.0.png) | ![](images/defocusAngle/0.5.png) | ![](images/defocusAngle/1.0.png) |

### De-focus Distance

Defoucs Distance, When we have depth of field ~ we have a field and objects lying in this field will seem sharp and objects further or before this feild would blur. This value helps us to move the depth of field around

| defocus Distance | defocus Distance |
|-------|---------|
| ![](images/defocusDistance/render1.png) | ![](images/defocusDistance/render2.png) |

### FOV

FOV (Field of View) refers to the extent of the observable world that is seen at any given moment. We control this using vertical FOV

| fov 20 | fov 90 |
|-------|---------|
| ![](images/fov/20.png) | ![](images/fov/90.png) |

### Max Depth & SPP

Max Depth refers to how many bounces each ray can potentially have. More number allows more information to gather and less leads to less number to gather

SPP: sampling rate, basically how many extra rays should we cast per ray. More rays mean more values to average for a certain pixel. Fun Fact: since for SPP we cast extra rays, it's additional cost, the DOF uses this additional cost to it's benefit and implements blurring by smartly deviating the rays 

| max Depth 2 SPP 500 | max Depth 10 SPP 500|
|---------|--------|
| ![](images/maxDepth/maxdepth2samplerate500.png) | ![](images/maxDepth/maxdepth10samplerate500.png) |

| max Depth 50 SPP 2 | max Depth 50 SPP 50 | 
|--------------------|---------------------|
| ![](images/maxDepth/maxdepth50samplerate2.png) | ![](images/maxDepth/maxdepth50samplerate50.png) | 

| max Depth 2 SPP 2 | max Depth 50 SPP 500 |
|-------------------|----------------------|
| ![](images/maxDepth/maxdepth2samplerate2.png) | ![](images/maxDepth/maxdepth50samplerate500.png) |
