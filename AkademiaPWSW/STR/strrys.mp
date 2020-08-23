input TEX

def Node(expr v, d)=
    begingroup
        save node; path node;
        node := fullcircle scaled d shifted v;
        node
    endgroup
enddef;

vardef Nodecen(expr pv)=
    save $; pair $; $ := center pv; $
enddef;

def nodein(expr pv, txt)=
    begingroup
        draw pv;
        label(TEX(txt), Nodecen(pv));
    endgroup
enddef;

def node(expr pv, txt)=
    begingroup
        unfill pv;
        nodein(pv, txt);
    endgroup
enddef;

def Edge(expr pv, pu, dev)=
    begingroup
        save ed, v, u, ipv, ipu, ang;
        path ed; pair v, u, ipv, ipu; numeric ang;
        v := Nodecen(pv); u := Nodecen(pu);
        ang := angle(u-v) + dev;
        ed := v{dir ang}..u;
        ipv := ed intersectionpoint pv;
        ipu := ed intersectionpoint pu;
        ed := ipv{dir ang}..ipu;
        ed
    endgroup
enddef;

def edgepath(expr ed, t)=
    begingroup
        if t = 1: drawarrow ed;
        elseif t = 2: drawdblarrow ed;
        else: draw ed;
        fi
    endgroup
enddef;

beginfig(1);
    u := 1cm;
    
    pair V[];
    V1 := (1.2u, 2.4u); V2 := (1.2u, 1.2u);
    V3 := (2.4u, 1.2u); V4 := (0, 1.2u);
    V5 := (1.2u, 0); V6 := (0, 2.4u);
    V7 := (0, 0); V8 := (2.4u, 0);
    
    path PV[];
    for i=1 upto 8:
        PV[i] := Node(V[i], 0.6u);
    endfor;
    
    path ED[];
    ED2 := Edge(PV1, PV2, 0);
    ED3 := Edge(PV2, PV3, 0);
    ED4 := Edge(PV2, PV4, 0);
    ED5 := Edge(PV2, PV5, 0);
    ED6 := Edge(PV4, PV6, 0);
    ED7 := Edge(PV4, PV7, 0);
    ED8 := Edge(PV5, PV8, 0);
    
    for i=1 upto 8:
        node(PV[i], decimal i);
    endfor;
    for i=2 upto 8:
        edgepath(ED[i], 0);
    endfor;
    
endfig;
end;
