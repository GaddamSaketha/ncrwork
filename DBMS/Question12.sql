use sampp;
select min(sal)"min sal",max(sal)"max sal" ,job from emp group by job;