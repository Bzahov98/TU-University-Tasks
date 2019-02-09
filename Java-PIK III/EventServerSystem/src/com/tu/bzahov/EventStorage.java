package com.tu.bzahov;

import java.util.ArrayList;
import java.util.List;

public class EventStorage {
    private static List<Event> events = new ArrayList<>();

    public synchronized static List<Event> onShowAllEvents(String town, String date){
        List<Event> result = new ArrayList<>();
        for (Event event: events) {
            if (date.equals(event.getDate())){
                if (town.equals(event.getTown())){
                    result.add(event);
                }
            }
        }
        return result;
    }

    public synchronized static void onAddNewParticipant(int id){

        for (Event event: events) {
            if (id == event.getId()){
                int count = event.getAvailablePartipCount();
                if (count > 0){
                    event.setAvailablePartipCount(count-1);
                }
            }
        }
    }
}
