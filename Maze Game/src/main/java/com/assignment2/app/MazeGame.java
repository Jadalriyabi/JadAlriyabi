package com.assignment2.app;

public class MazeGame {
    public Maze createMaze(MazeFactory factory) {
        Maze a_Maze = factory.makeMaze();
        Room room_1 = factory.make_Room();
        Room room_2 = factory.make_Room();
        Door the_Door = factory.make_Door(room_1, room_2);
        a_Maze.add_Room(room_1);
        a_Maze.add_Room(room_2);
        room_1.setSide(Direction.North, factory.make_Wall());
        room_1.setSide(Direction.East, the_Door);
        room_1.setSide(Direction.South, factory.make_Wall());
        room_1.setSide(Direction.West, factory.make_Wall());
        room_2.setSide(Direction.North, factory.make_Wall());
        room_2.setSide(Direction.East, factory.make_Wall());
        room_2.setSide(Direction.South, factory.make_Wall());
        room_2.setSide(Direction.West, the_Door);
        return a_Maze;
    }
}