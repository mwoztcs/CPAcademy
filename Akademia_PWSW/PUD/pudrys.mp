beginfig(1);
    u := 1cm;

    draw (0, 0)--(3u, 0)--(3u, 2u)--(0, 2u)--cycle;
    draw (0.2u, 0.1u)--(2u, 0.1u)--(2u, 1.5u)--(0.2u, 1.5u)--cycle;
    draw (2.2u, 0.1u)--(2.8u, 0.1u)--(2.8u, 1.5u)--(2.2u, 1.5u)--cycle;
    draw (0.4u, 0.2u)--(1u, 0.2u)--(1u, 1u)--(0.4u, 1u)--cycle;
    draw (1.2u, 0.2u)--(1.8u, 0.2u)--(1.8u, 1u)--(1.2u, 1u)--cycle;

    label.lrt("1", (0, 2u));
    label.lrt("2", (0.2u, 1.5u));
    label.lrt("3", (2.2u, 1.5u));
    label.lrt("4", (0.4u, 1u));
    label.lrt("5", (1.2u, 1u));
endfig;
end;
