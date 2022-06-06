<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title>CID Assignment</title>

<!--

U08B interactive pizza ordering

What objectives are you demonstrating?

(place here)

-->

<style>


</style>

</head>
<body>
<?php

// Show errors, but not all...
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Get data from a GET or POST (change GET to POST for post)
if(isset($_GET['data'])) { $data = $_GET['data']; } else { $data = ""; }

print "(body of your project) $data";

for($i; $i < 10; $i++) { print " $i"; }

?>
</body>
</html>