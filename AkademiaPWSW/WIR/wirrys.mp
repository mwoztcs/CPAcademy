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

vardef Edgepoint(expr ed, t)=
    save $; pair $; $ := point (t*(length ed)) of ed; $
enddef;

def edgepath(expr ed, t)=
    begingroup
        if t = 1: drawarrow ed;
        elseif t = 2: drawdblarrow ed;
        else: draw ed;
        fi
    endgroup
enddef;

def edgelabel(suffix pos)(expr ed, t, txt)=
    begingroup
        label.pos(TEX(txt), Edgepoint(ed, t));
    endgroup
enddef;

beginfig(1);
    u := 1.2cm;
    
    pair V[];
    V1 := (0, 0); V2 := (1.5u, 0);
    V3 := (3u, 0); V4 := (4.5u, 0);
    V5 := (3u, 1.5u); V6 := (4.5u, 1.5u);
    
    path PV[];
    PV1 := Node(V1, 0.6u); PV2 := Node(V2, 0.6u);
    PV3 := Node(V3, 0.6u); PV4 := Node(V4, 0.6u);
    PV5 := Node(V5, 0.6u); PV6 := Node(V6, 0.6u);
    
    for i=1 upto 6:
        node(PV[i], decimal i);
    endfor;

    path ED[];
    ED2 := Edge(PV1, PV2, 0);
    ED3 := Edge(PV2, PV3, 0);
    ED4 := Edge(PV3, PV4, 0);
    ED5 := Edge(PV3, PV5, 0);
    ED6 := Edge(PV5, PV6, 0);
    
    edgepath(ED2, 0); edgelabel(top)(ED2, 0.5, "0");
    edgepath(ED3, 0); edgelabel(top)(ED3, 0.5, "1");
    edgepath(ED4, 0); edgelabel(top)(ED4, 0.5, "0");
    edgepath(ED5, 0); edgelabel(lft)(ED5, 0.5, "1");
    edgepath(ED6, 0); edgelabel(top)(ED6, 0.5, "1");
endfig;
end;
