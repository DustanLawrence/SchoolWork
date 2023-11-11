# Display the first name and last name as well as department name of all current department managers. SORT by department name, last name, first name
SELECT e.first_name, e.last_name, d.dept_name
FROM employees e
JOIN dept_manager dm ON e.emp_no = dm.emp_no
JOIN departments d ON dm.dept_no = d.dept_no
WHERE dm.to_date = '9999-01-01'
ORDER BY d.dept_name, e.last_name, e.first_name;
