input TEX

def addFire(expr v, u)=
    begingroup
        save deva, devb;
        pair deva, devb;
        deva := (0.25u, 0.25u);
        devb := (-0.25u, 0.25u);

        draw v+deva -- v-deva;
        draw v+devb -- v-devb;
    endgroup
enddef;

def addHouse(expr v, u)=
    begingroup
        save deva, devb;
        pair deva, devb;
        deva := (0.25u, 0);
        devb := (0, 0.25u);

        draw v+deva .. v+devb .. v-deva .. v-devb .. cycle;
    endgroup
enddef;

beginfig(1);
    u := 1cm;

    for i=-1 upto 3:
        label.lft(decimal i, (-1.5u, i*u));
        draw (-1.5u, i*u)--(2.5u, i*u) dashed withdots;
    endfor;
    for i=-1 upto 2:
        label.bot(decimal i, (i*u, -1.5u));
        draw (i*u, -1.5u)--(i*u, 3.5*u) dashed withdots;
    endfor;

    addHouse((0, 1u), u);
    addHouse((1u, -1u), u);
    addHouse((2u, 2u), u);

    addFire((2u, 0), u);
    addFire((-1u, -1u), u);
    addFire((1u, 3u), u);
    addFire((0, 1u), u);

    addHouse((-1.5u, -2.5u), u);
    label.rt(TEX("- remiza"), (-1.25u, -2.5u));

    addFire((0.75u, -2.5u), u);
    label.rt(TEX("- po\.zar"), (1u, -2.5u));
endfig;
end;
