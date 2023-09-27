package com.assignment2.app;

class DoorNeedingSpell extends Door{

    DoorNeedingSpell(Room room_1, Room room_2){
        super(room_1, room_2);
    }

    public String toString(){
        return super.toString() + "(Need a spell)";
    }
}