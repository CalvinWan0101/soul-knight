#pragma once

enum class Tag {
    PLAYER,
    MONSTER,
    PROJECTILE,
    DROP,
    
    PLAYER_ATTACK,
    MONSTER_ATTACK,
    
    PLAYER_WEAPON,
    MONSTER_WEAPON,
    
    TRANSFER_GATE,
    OBSTACLE,

    PLAYER_ALERTABLE,
    INTERACTABLE,

    DEAD,

    REMOVE_ON_NEXT_FRAME,

    
    Count // For calculate tags num in bitset.
};
