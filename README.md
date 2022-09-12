# SlnxWM
Selenux's Custom DWM

# SlnxWM Screenshots

<img width="33%" src="https://github.com/ItzSelenux/ItzSelenux.github.io/blob/main/res/pages/slnxwm/slnxwm1.png">   <img width="33%" src="https://github.com/ItzSelenux/ItzSelenux.github.io/blob/main/res/pages/slnxwm/slnxwm2.png">      <img width="33%" src="https://github.com/ItzSelenux/ItzSelenux.github.io/blob/main/res/pages/slnxwm/slnxwm3.png">
- NOTE: This is vanilla dwm bar not dwmblocks or polybar. 

# Requirements

- imlib2 
- xsetroot package ( show clock or other info on bar)

## Optional Requirements

- Rofi (Programs Laucher and Logout Menu)
- NerdFonts (by default, SlnxWM has symbols on Workspaces and Layouts)
   - i use https://github.com/ryanoasis/nerd-fonts
- Feh (Wallpaper)
- Picom (Window Compositor and Effects)
- KDocker (Send to tray, to minimize or send to other workspace)
- Desire to use DWM


# Setup 

```git clone https://github.com/ItzSelenux/slnxwm --depth 1```

```mv slnxwm ~/.local/share/```

```cd ~/.local/share/slnxwm```

- SlnxWM has a simple compilation script, you can also use it to recompile

```./remake```

remake has ```rm config.h``` and ```su -c "make install"``` inside

# Extra Setup

- to apply nerdfonts, download it, and put it on ```~/.local/share/fonts```

- if you want my Rofi theme or Picom config, you can copy it
 
 Rofi Theme:
  
```cp /extra/MintMenu-Green-Dark ~/.local/share/rofi/themes```
  
 Picom Config
  
```cp /extra/picom.conf ~/.config/```

- if you want to change autostart, open ```scripts/autostart```

# Run SlnxWM
Using ```startx``` or ```sx```


if you use startx
```
cp ~/.local/share/slnxwm/extra/.xinitrc ~/
```
if you use sx
```
cp ~/.local/share/slnxwm/extra/.xinitrc ~/.config/sx/sxrc
```
- the prepared file has ```exec ~/.local/share/slnxwm/scripts/./autostart``` inside

# Recompile 
- You need to recompile dwm after every change you make in its src code 

```cd ~/.local/share/slnxwm/```

```./remake```
- remake  is a script that do ```rm config.h ``` and ```su -c "make install"```

# Patches
- functionalgaps
- systray
- pertag
- titlecolor

you can view patches on ```patches``` folder

# DWM 
-SlnxWM is a fork of [DWM](https://dwm.suckless.org). 
