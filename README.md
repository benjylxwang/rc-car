# rc-car

An Arduino project for a fully functioning remote control car

## Communication Protocol 

Communication between controller and car is over the nRF24L01 modules. These allow for the sending and receiving of a 32 byte payload.

### Controller to Car
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
            <td>9-31</td>
            <td><i>Not in use</i></td>
            <td></td>
        </tr>
    </tbody>
</table>

### Car to Controller
The following is a list of all the sensor and state data that will be sent back and their position in the payload:


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
            <td rowspan=4>Speed</td>
            <td rowspan=4>float</td>
        </tr>
        <tr>
            <td>1</td>
        </tr>
        <tr>
            <td>2</td>
        </tr>
        <tr>
            <td>3</td>
        </tr>
        <tr>
            <td>4</td>
            <td rowspan=1>Turning Angle</td>
            <td rowspan=1>int8</td>
        </tr>
        <tr>
            <td>5</td>
            <td rowspan=3><i>Unused</i></td>
        </tr>
        <tr>
            <td>6</td>
        </tr>
        <tr>
            <td>7</td>
        </tr>
        <tr>
            <td>8</td>
            <td>Indicators (Left/Right/Off)</td>
            <td>int8</td>
        </tr>
        <tr>
            <td>9</td>
            <td>Is Auto Headlights On?</td>
            <td>bool</td>
        </tr>
        <tr>
            <td>10</td>
            <td>Is Manual Headlights On?</td>
            <td>bool</td>
        </tr>
        <tr>
            <td>11</td>
            <td>Is Hazard Lights on?</td>
            <td>bool</td>
        </tr>
        <tr>
            <td>12</td>
            <td rowspan=4>Temperature</td>
            <td rowspan=4>float</td>
        </tr>
        <tr>
            <td>13</td>
        </tr>
        <tr>
            <td>14</td>
        </tr>
        <tr>
            <td>15</td>
        </tr>
        <tr>
            <td>16</td>
            <td rowspan=4>Humidity</td>
            <td rowspan=4>float</td>
        </tr>
        <tr>
            <td>17</td>
        </tr>
        <tr>
            <td>18</td>
        </tr>
        <tr>
            <td>19</td>
        </tr>
        <tr>
            <td>20</td>
            <td>Is Horn on?</td>
            <td>bool</td>
        </tr>
        <tr>
            <td>21-31</td>
            <td><i>Not in use</i></td>
            <td></td>
        </tr>
    </tbody>
</table>