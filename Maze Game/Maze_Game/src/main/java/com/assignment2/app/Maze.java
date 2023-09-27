package com.assignment2.app;
import java.util.*;

class Maze{

    private Set<Room> rooms = new HashSet<Room>();

    Maze(){
        System.out.println("creating a Maze");
    }

    //add Room
    void add_Room(Room r) {
        if (!rooms.contains(r)) {
            rooms.add(r);
        }
    }
}