# You will need two queries for this one. It can be done in one but it will require too much copying.
# Using the previous query, create a view (this will help you from copy pasting it) and display the ratio of women to men for each department. Display department and ratio rounded in 2 decimals points.
# For the view use: CREATE OR REPLACE VIEW
# Otherwise scripts will fail if a view exists

CREATE OR REPLACE VIEW EmployeeGenderData AS
SELECT d.dept_name AS department, e.gender
FROM employees e
JOIN dept_emp de ON e.emp_no = de.emp_no
JOIN departments d ON de.dept_no = d.dept_no
WHERE de.to_date = '9999-01-01';

SELECT department,
    ROUND(SUM( gender = 'F' ) / SUM( gender = 'M'), 2) AS ratio
FROM EmployeeGenderData
GROUP BY department;


