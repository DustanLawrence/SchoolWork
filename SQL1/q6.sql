# Display the age of the oldest employee (as an int) in absolute years (assuming they are still working there)
SELECT CAST(DATEDIFF(NOW(), birth_date)/365 AS SIGNED) AS age FROM employees NATURAL JOIN dept_emp WHERE to_date = '9999-01-01'  ORDER BY age DESC LIMIT 1
#SELECT TIMESTAMPDIFF(YEAR, birth_date, NOW()) AS age FROM employees ORDER BY age DESC Limit 1
