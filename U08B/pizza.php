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
h1{
	text-align:center;
	font-size:4.0em;
	}
	
	body{
	margin:50px 0px; padding:10px;
    text-align:center;
    align:center;
	background-color: #EBA586;
	}	
	
</style>

</head>
<body>
<?php

// Show errors, but not all...
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Get data from a GET or POST (change GET to POST for post)
if(isset($_POST["name"])) { $name = $_POST["name"]; } else { $name = ""; }
if(isset($_POST["size"])) { $size = $_POST["size"]; } else { $size = ""; }
if(isset($_POST["pepp"])) { $pepp = $_POST["pepp"]; } else { $pepp = ""; }
if(isset($_POST["mush"])) { $mush = $_POST["mush"]; } else { $mush = ""; }
if(isset($_POST["saus"])) { $saus = $_POST["saus"]; } else { $saus = ""; }
if(isset($_POST["oliv"])) { $oliv = $_POST["oliv"]; } else { $oliv = ""; }
$total=0;
$tax=0;
if($size == 'Small'){
	$total+=9.99;
	}
if($size == 'Medium'){
	$total+=12.99;
	}
if($size == 'Large'){
	$total+=15.99;
	}


print "
<h1>Pizza Orders Made Easy</h1><br />
<h2>Reciept</h2>
<p>Customer Name: $name </p>
<p>Pizza Size: $size - $$total</p> 
";
if($mush){$total+=2.99;
print"<p>Mushroom's-$2.99</p>";
	}
if($oliv){$total+=2.99;
print"<p>Olives-$2.99</p>";}
if($pepp){$total+=2.99;
print"<p>Pepperonni-$2.99</p>";}
if($saus){$total+=2.99;
print"<p>Sausage-$2.99</p>";}
print"<p>Total Due: $$total</p>";

?>
</body>
</html>
