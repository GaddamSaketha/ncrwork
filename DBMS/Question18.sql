use sampp;
select * from emp e where e.sal=(select min(sal) from emp where e.mgr=mgr) and e.sal>1000;