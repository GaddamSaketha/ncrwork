use sampp;
SELECT empno, count(*)"emp count" FROM emp
GROUP BY empno having count(empno)>1;
