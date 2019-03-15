use sampp;
select deptno,count(*)"employee count"  from emp group by deptno having count(*)>3;