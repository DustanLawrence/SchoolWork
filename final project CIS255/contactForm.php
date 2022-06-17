
<style>
 body {
        background-image: url('duckprint.png');         
    }
	#thanks{
		 display:block;
		 width:65%;
		 margin-left: auto;
         margin-right: auto; 
	}
	#header { 
        display: block;
        margin-left: auto;
        margin-right: auto; 
        width: 1200px;
        height: 250px; 
        background-color: #0e2f44;
        border-radius: 100px;
}
</style>

</head>
<body >
<?php

// Show errors, but not all...
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Get data from a POST 
if(isset($_POST["fName"])) { $fName = $_POST["fName"]; } else { $fName = ""; }
if(isset($_POST["lName"])) { $lName = $_POST["lName"]; } else { $lName = ""; }
if(isset($_POST["email"])) { $email = $_POST["email"]; } else { $email = ""; }
if(isset($_POST["mess"])) { $mess = $_POST["mess"]; } else { $mess = ""; }
if(isset($_POST["messInput"])) { $messInput = $_POST["messInput"]; } else { $messInput = ""; }
if(isset($_POST["addr"])) { $addr = $_POST["addr"]; } else { $addr = ""; }
if(isset($_POST["city"])) { $city = $_POST["city"]; } else { $city = ""; }
if(isset($_POST["state"])) { $state = $_POST["state"]; } else { $state = ""; }
if(isset($_POST["phone"])) { $phone = $_POST["phone"]; } else { $phone = ""; }
if(isset($_POST["location"])) { $location = $_POST["location"]; } else { $location = ""; }
//add title image to page
print"<center><div id='header'><img src='quackshacklogo.jpg' class='imagelogo' alt='logo'  /></div></center>";
//create thank you title
print "<h1 style='text-align:center; font-family:ravie;'>Thank You</h1>
<div id='thanks'><p>We appreciate  your Business and your feedback ";
//if customer supplied name print name esle print valued customer
if($fName)print"$fName ";else print"valued Customer";
if($lName)print"$lName. "; else print". ";
print "We have received  ";
//print message that goes with message selected
if($messInput == 'question')print"your question about the $location Quack Shack.";
if($messInput == 'like')print"what you liked about the $location Quack Shack.";
if($messInput == 'dislike')print"what you disliked about the $location Quack Shack.";
if($messInput == 'suggestion')print"your suggestion about the $location Quack Shack.";
print"The $messInput of <strong>\"$mess\"</strong> has been sent to headquarters for review.</p>" ;
print"<p>We will Email any response to $email for any questions or updates.</p>";
//print optional inputs if used
if($addr)print"<p>You also provided a contact address of $addr $city, $state.</p>";
if($phone)print"<p>You also provided a contact phone number of $phone.</p></div>";
//return to contact page
print"<a id='thanks' href='contactPage.html' />Back to Contact page.</a>";
?> 

</body>
</html>