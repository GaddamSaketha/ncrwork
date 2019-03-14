use sampp;
select ename,12*sal "annual salary",comm from emp where job='salesman' and sal>isnull(comm,0) order by sal desc,ename ;