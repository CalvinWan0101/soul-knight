# Soul Knight

The boss shows up in 1-5 and 3-5, so please fight until the end.

## Demo Video
[![YouTube](http://i.ytimg.com/vi/uLHkTPGW0ko/hqdefault.jpg)](https://www.youtube.com/watch?v=uLHkTPGW0ko)

## Warning (Please read before playing)
Displaying translucent objects can cause lag; some computers handle it normally while others experience severe lag (currently, it seems that 40 series graphics cards all experience lag). Therefore, if displaying the red damage effect when taking damage causes the entire game to freeze, please go to config.h and change the last item, `TRANSLUCENT_EFFECT`, to `false`. This will cause the poison circle to become a solid green circle and obstruct the view.


## Game Controls
- "W", "A", "S", "D" : Move.
- "Q" : Activate character skill. There is a skill cooldown progress bar at the bottom right of the screen. The skill can only be used again once the cooldown is complete.
- "E" : Switch weapon (effective only when holding two weapons).
- "F" : Interact with interactive items, e.g., enter portals, purchase items, pick up weapons or potions, open chests, etc. A prompt will appear above when near an interactive item.
- "Move mouse" : Aim at enemies.
- "Left mouse button" : Use weapon to attack.

## Debug Mode
If you want to make the game easier, you can change the weapon of `Knight` from `BadPistol` to `GatlingGun` in `Knight.cpp` (line 26).

**The number keys**
1. Display / Hide hitbox
2. Restore 100 MP
3. Restore 1 HP
4. Obtain 100 gold coins
5. Invincibility mode
6. Wallhack mode (Please do not ignore monsters and use wallhack to enter the portal to the next level after the room starts)
7. All monsters on the field receive 50 damage and all bullets are cleared
8. Obtain a weapon chest (can open to get a random weapon)
