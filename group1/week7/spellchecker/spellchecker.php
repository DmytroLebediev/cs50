<?php
    if ($_SERVER['REQUEST_METHOD'] != 'POST'
        || !isset($_POST["selectedfile"]))
    {
        header("Location: stub.php");
        exit;
    }
    else
    {
        require("dictionary.php");
    }
?>

<!DOCTYPE html>

<html>
    <head>
        <title>checker</title>
        <link rel="stylesheet" href="styles.css">
    </head>
    <body>
        <div id="checkedtext">
            <?php
                load();
                $lines = file("./texts/".$_POST["selectedfile"]);
                foreach ($lines as $line)
                {
                    $words = preg_split("/\W+/", $line);
                    foreach ($words as $word)
                    {
                        if (!empty($word))
                        {
                            if (!check(strtolower($word)))
                            {
                                echo "<span class='wrongword'>$word</span>";
                            }
                            else
                            {
                                echo $word;
                            }
                            echo " ";
                        }
                    }
                    echo "<br>";
                }
            ?>
        </div>
        
        <?php
            require("footer.php");
        ?>
    </body>
</html>