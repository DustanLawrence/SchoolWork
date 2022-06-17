<style>
    body {
        background-image: url('duckprint.png');
    }
    .imagelogo {
        display:block;
        border-radius: 100px;
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
<?php
    // Ian Lorimer Assignment U09A Group Project
    // Use of PHP
    // Use a webform
    // Use of PHP conditional statements
    // Created client server event using PHP and webpage
    echo '<body>';
    echo '<center><div id="header"><img src="quackshacklogo.jpg" class="imagelogo" alt="logo"  /></div></center>';
    echo '<center><h1>Your Quack Shack Order</h1></center>';
    // Show errors, but not all...
    error_reporting(E_ALL);
    ini_set('display_errors', 1);
    // print Restaurant name
    // Create table for receipt
    $s = <<<EOD
    <center><table>
    <thead>
        <tr>
            <th>Item</th>
            <th>Quantity</th>
            <th></th>
            <th></th>
            <th>Subtotal</th>
        </tr>
    </thead>
    <center><tbody>
    EOD;
    echo $s;
    // Get receipt from a GET
    $i=0;
    $total = 0;
    // Seattle tax rate could be changed for different locations
    $taxRate = 0.102;
    while(isset($_GET['n' . $i]))
    {
        // Creates receipt based on what the user selected
        if($_GET['q' . $i] != '')
        {
            $q = +$_GET['q' . $i];
            $p = $_GET['p' . $i];
            $p = +substr($p,1);
            $subtotal = $p * $q;
            $total += $subtotal;
            // Print receipt
            echo '<tr><td>' . $_GET['n' . $i] . '</td>';
            echo '<td style="text-align:center">' . $q . '</td>';
            echo '<td></td>';
            echo '<td></td>';
            echo '<td style="text-align:right"> $'. number_format($subtotal, 2) . '</td></tr>';
        }
        $i++;
    }
    echo '</tbody></table><br/><br/>';
    echo '<center><table>';
    echo '<tr><th>Total</th><td style="width:20px"></td><td style="text-align:right"> $' . number_format($total, 2) . '</td></tr>';
    echo '<tr><th>Tax</th><td style="width:20px"></td><td style="text-align:right"> $' . number_format($total * $taxRate, 2) . '</td></tr>';
    echo '<tr><th>Grand Total</th><td style="width:20px"></td><td style="text-align:right"> $' . number_format($total * (1 + $taxRate), 2) . '</td></tr></table></center><br/><br/>';
    echo '<h2>Thank you for your business!</h2>';
    echo '</body>';
?>
