package com.tu.bzahov.competitions;

import com.tu.bzahov.interfaces.ICompetition;
import com.tu.bzahov.Participant;

public class HorseCompetition implements ICompetition {
    private String breed;
    private static Participant[] schedule = null;

    public HorseCompetition() {}

    public HorseCompetition(String breed) {
        this.breed = breed;
    }

    @Override
    public Participant[] getSchedule() {
        return schedule;
    }

    @Override
    public void setSchedule(Participant[] schedule) {
        HorseCompetition.schedule = schedule;
    }

}
