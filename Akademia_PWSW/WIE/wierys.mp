input TEX

def Nodesq(expr v, a)=
    begingroup
        save node; path node;
        node := ((a, (a/2))--(a, a)--((a/2), a)--(0, a)--(0, (a/2))--(0, 0)--((a/2), 0)--(a, 0)--cycle) shifted (xpart v - (a/2), ypart v - (a/2));
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

def nodecolor(expr pv, clr, txt)=
    begingroup
        fill pv withcolor clr;
        nodein(pv, txt);
    endgroup
enddef;

beginfig(1);
    u := 0.8cm;

    numeric T[];
    T[3] := 1; T[4] := 1; T[5] := 1;
    T[6] := 1; T[7] := 2; T[8] := 2;
    T[9] := 1; T[10] := 2; T[11] := 3;
    
    string S[];
    S[1] := "1 0"; S[2] := "2 1"; S[3] := "3 0";
    S[4] := "1 0"; S[5] := "2 0"; S[6] := "3 1";

    for i=1 upto 3:
        for j=1 upto 3:
            path pv;
            pv = Nodesq((i*u, j*u), 0.9u);
            if (j = 3) or (i = 2):
                node(pv, decimal T[3*i+j-1]);
            else:
                nodecolor(pv, (0, 0, 0, 0.2), decimal T[3*i+j-1]);
            fi             
        endfor;
    endfor;

    for i=1 upto 3:
        label(TEX(S[i]), (i*u, 0u));
    endfor;
    for i=1 upto 3:
        label(TEX(S[i+3]), (-0.1u, i*u));
    endfor;
        
endfig;
end;
