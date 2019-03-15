use sampp;
select job,ename,sal from emp e1 where sal=(select max(sal) from emp where job=e1.job) order by sal desc;