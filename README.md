# rc-car

An Arduino project for a fully functioning remote control car

## Communication Protocol

Communication between controller and car is over the nRF24L01 modules. These allow for the sending and receiving of a 32 byte payload.

The following is a list of all the controls needed and their position in the payload:

<table>
    <thead>
        <tr>
            <th>Byte #</th>
            <th>Control</th>
            <th>Type</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>0</td>
            <td rowspan=2>Throttle (Forwards/Backwards)</td>
            <td rowspan=2>int16</td>
        </tr>
        <tr>
            <td>1</td>
        </tr>
        <tr>
            <td>2</td>
            <td rowspan=2>Turning (Left/Right)</td>
            <td rowspan=2>int16</td>
        </tr>
        <tr>
            <td>3</td>
        </tr>
        <tr>
            <td>4</td>
            <td>Indicators (Left/Right/Off)</td>
            <td>int8</td>
        </tr>
        <tr>
            <td>5</td>
            <td>Toggle Automatic Headlights</td>
            <td>bool</td>
        </tr>
        <tr>
            <td>6</td>
            <td>Toggle Headlights (Only has effect if in manual mode)</td>
            <td>bool</td>
        </tr>
        <tr>
            <td>7</td>
            <td>Toggle Hazard Lights</td>
            <td>bool</td>
        </tr>
        <tr>
            <td>8</td>
            <td>BEEEEEEP</td>
            <td>bool</td>
        </tr>
        <tr>
            <td>8-31</td>
            <td><i>Not in use</i></td>
            <td></td>
        </tr>
    </tbody>
</table>
