package com.assignment2.app;

class Door extends MapSite {

    private static int _doorCnt = 1;
    private int _doorNr;
    private Room _room1;
    private Room _room2;

    Door(Room r1, Room r2) {
        _doorNr = _doorCnt++;
        System.out.println("creating a Door #" + _doorNr + " between " + r1 + " and " + r2);
        _room1 = r1;
        _room2 = r2;
    }
    public String toString() {
        return "Door #" + new Integer(_doorNr).toString();
    }
}