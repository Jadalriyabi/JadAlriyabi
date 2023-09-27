package com.assignment2.app;

class MazeFactory {
    //Make a new Maze
    public Maze makeMaze(){
        return new Maze();
    }

    //Making a new Room
    public Room make_Room(){
        return new Room();
    }

    //Making a new Wall
    public Wall make_Wall() {
        return new Wall();
    }

    //Making a new Door
    public Door make_Door(Room r1, Room r2){
        return new Door(r1, r2);
    }
}
