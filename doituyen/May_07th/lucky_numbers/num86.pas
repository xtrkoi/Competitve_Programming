const   fi = 'num86.inp';
        fo = 'num86.out';
type    mang = record
        a, b, du: longint;
        end;
var     n, x, d, c, a, b :longint;
        dd      : array[1..400000] of mang;
        q       : array[1..400000] of longint;
        s       : array[6..8,1..3] of integer;
        g, f    : text;
        dis     : boolean;

procedure xuli;
var     i, j, l, u, v: longint;
begin
        d := 0; 
        c := 2; 
        q[1] := 6; 
        q[2] := 8;

        dd[1].a := 0;
        dd[1].b := 1;
        dd[1].du := 6 mod x;
        
        dd[2].a := 1;
        dd[2].b :=0;
        dd[2].du := 8 mod x;
        repeat
                inc(d);

                u := q[d];
                j := 1;
                v := s[q[d],j];

                while v<>0 do
                begin
                        inc(c);
                        q[c] := v;
                        if v = 6 then
                                begin
                                        dd[c].b := dd[d].b+1;
                                        dd[c].a := dd[d].a;
                                        dd[c].du := (dd[d].du * 10 + 6) mod x;
                                end
                        else
                                begin
                                        dd[c].a := dd[d].a+1;
                                        dd[c].b := dd[d].b;
                                        dd[c].du := (dd[d].du * 10 + 8) mod x;
                                end;
                        inc(j);
                        v := s[q[d],j];

                end;
        until (dd[d].a + dd[d].b > 200) or (dd[d].du = 0) ;
        if dd[d].a + dd[d].b > 200 then writeln(f,'-1') else
        begin
                for i:=1 to  dd[d].a do write(f,'8');
                for i:=1 to  dd[d].b do write(f,'6'); writeln(f);
        end;

end;


procedure nhap;
var i:longint;
begin
        assign(g,fi);assign(f,fo);
        rewrite(f);
        reset(g);
        readln(g,n);
        s[6,1]:=6;
        s[6,2]:=0;
        s[8,1]:=6;
        s[8,2]:=8;
        s[8,3]:=0;
        for i:=1 to n do
        begin
                readln(g,x);
                if x mod 10 <> 5 then
                xuli else
                writeln(f,'-1');
        end;
        close(g);close(f);

end;

begin
        nhap
end.