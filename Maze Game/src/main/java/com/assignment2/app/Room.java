package com.assignment2.app;

class Room extends MapSite{
    private int room_nr;
    private static int room_count = 1;
    private MapSite north_Side;
    private MapSite south_Side;
    private MapSite east_Side;
    private MapSite west_Side;

    Room(){
        room_nr = room_count++;
        System.out.println("creating Room #" + room_nr);
    }

    void setSide(Direction d, MapSite site) {
        switch(d){
            case North: north_Side = site;
            case South: south_Side = site;
            case East: east_Side = site;
            case West: west_Side = site;
        }
        System.out.println("Setting: " + d.toString() + " side of " + this.toString() + " to " + site.toString());
    }

    MapSite getSide(Direction d) {
        MapSite result = null;
        switch(d){
            case North: result = north_Side;
            case South: result = south_Side;
            case East: result = east_Side;
            case West: result = west_Side;
        }
        return result;
    }

    public String toString(){
        return "Room #" + Integer.toString(room_nr);
    }
}