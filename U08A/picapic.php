<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title>CID Assignment</title>

<!--

CID Name Assignment

What objectives are you demonstrating?

(place here)

-->

<style>
margin:4%;

</style>

</head>
<body>

<?php

// Show errors, but not all...
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Get data from a GET or POST (change GET to POST for post)
if(isset($_GET["car"])) { $car = $_GET["car"]; } else { $car = ""; }
if(isset($_GET["truck"])) { $truck = $_GET["truck"]; } else { $truck = ""; }
if(isset($_GET["motorcycle"])) { $motorcycle = $_GET["motorcycle"]; } else { $motorcycle = ""; }

print "
<style>

</style>
<h1>PIC-A-PIC</h1>
<form method='get' action='picapic.php'>
<p><b>Pick A Picture</b><br />
<input id='car' type='radio' name='pic'>Car</input><br />
<input id='truck' type='radio' name='pic'>Truck</input><br />
<input id='motorcycle' type='radio' name='pic'>Motor Cycle</input><br />
<input type='button' value='Submit' />
</form>
</p>
";



?>
</body>
</html>