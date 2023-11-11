# Display the first_name, last_name, latest salary of the 10 higher salaried employees still actively working in the company
#SELECT first_name, last_name, salary FROM employees NATURAL JOIN dept_emp NATURAL JOIN salaries WHERE to_date = 9999-01-01;
SELECT e.first_name, e.last_name, s.salary
FROM employees e
INNER JOIN dept_emp de ON e.emp_no = de.emp_no
INNER JOIN salaries s ON e.emp_no = s.emp_no
WHERE de.to_date = '9999-01-01' -- Still actively working
AND s.to_date = (
    SELECT MAX(to_date)
    FROM salaries
    WHERE emp_no = e.emp_no
)
ORDER BY s.salary DESC
LIMIT 10;