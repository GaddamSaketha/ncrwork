use sampp;
select ENAME,loc,dept.deptno,dname,sal from emp,dept
where emp.deptno=dept.deptno and sal>1500;