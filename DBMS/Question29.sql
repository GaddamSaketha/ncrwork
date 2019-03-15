use sampp;
select deptno, count(*)"employee count",sum(sal)"total salary",avg(sal)"average salary" from emp group by deptno;