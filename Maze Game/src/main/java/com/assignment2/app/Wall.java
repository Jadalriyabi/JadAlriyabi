package com.assignment2.app;

class Wall extends MapSite {

    private int wall_nr;
    private static int wall_count = 1;

    Wall(){
        wall_nr = wall_count++;
        System.out.println("creating Wall #" + Integer.toString(wall_nr));
    }

    public String to_String() {
        return "Wall #" + Integer.toString(wall_nr);
    }
}