use sampp;
select avg(sal), sum(sal+isnull(comm,0))"total renumeration",job from emp group by job;