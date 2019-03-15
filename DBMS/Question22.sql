use sampp;
SELECT ename,sal,grade FROM emp e, salgrade s WHERE (e.sal between s.losal and s.hisal) and grade=3;
