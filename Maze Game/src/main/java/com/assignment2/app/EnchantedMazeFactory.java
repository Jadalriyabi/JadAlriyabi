package com.assignment2.app;

class EnchantedMazeFactory extends MazeFactory{
    public Room makeRoom(){
        return new EnchantedRoom(castSpell());
    }

    public Door makeDoor(Room room_1, Room room_2){
        return new DoorNeedingSpell(room_1, room_2);
    }

    protected static Spell castSpell(){
        return new Spell();
    }
}
