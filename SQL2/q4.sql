# How many women and how many men are working on each department. Display three columns: dept name, gender and number of people working
SELECT d.dept_name, e.gender, COUNT(*) AS number_of_people
FROM employees e
INNER JOIN dept_emp de ON e.emp_no = de.emp_no
INNER JOIN departments d ON de.dept_no = d.dept_no
WHERE to_date = '9999-01-01'
GROUP BY d.dept_name, e.gender



