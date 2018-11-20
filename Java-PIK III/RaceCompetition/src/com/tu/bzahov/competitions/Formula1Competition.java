package com.tu.bzahov.competitions;

import com.tu.bzahov.interfaces.ICompetition;
import com.tu.bzahov.Participant;

public class Formula1Competition implements ICompetition {
    private String winnersTime;
    private static Participant[] schedule = null;

    public Formula1Competition() {}

    public Formula1Competition(String winnersTime) {
        this.winnersTime = winnersTime;
    }

    @Override
    public Participant[] getSchedule() {
        return schedule;
    }
    @Override
    public void setSchedule(Participant[] schedule) {
        Formula1Competition.schedule = schedule;
    }
}
