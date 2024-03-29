# SlnxWM
Selenux's Custom DWM

# Requirements

- imlib2
- xsetroot package ( show clock or other info on bar)

## Optional Requirements

- Rofi (Programs Laucher and Logout Menu)
- NerdFonts (by default, SlnxWM has symbols on Workspaces and Layouts)
   - i use https://github.com/ryanoasis/nerd-fonts
- Feh (Wallpaper)
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
- remake  is a script that do ```make clean```, ```rm config.h ``` and ```su -c "make install"```

# Patches
- functionalgaps
- baratanyedge
- modified awesomebar to get works with baratanyedge
- pertag

# DWM
-SlnxWM is a fork of [DWM](https://dwm.suckless.org).
