# cli-extension

Extension of the cli-project

# Description
Make a visual representation of the given blockchain<br>
Using a terminal ASCII chars<br>

# Upgrades
Filter for the visual representation

# Ideas
Due to the limited time, my first idea of using signals cannot work (would have to read the bytes etc)<br>
My second idea was to make an API, that would send requests with the new block data, but this is simply inefficient and quite hard for the given time<br>
My third idea is to use sockets, a simple socket that would send the new block data<br>

# Block Visualisation
As we know, a block is represented by those fields :
- index
- difficulty
- timestamp
- nonce
- previous hash
- block data
- block data len
- transactions
- hash

All these fields have to be displayed (unless a filter option is set)<br>
<br>
+-------------------------+<br>
| NEW BLOCK [index]       |<br>
|-------------------------|<br>
| Timestamp:              |<br>
| Difficulty:             |<br>
| Nonce:                  |<br>
| Previous hash:          |<br>
| Current hash:           |<br>
| Data:                   |<br>
|                         |<br>
| Transactions:           |<br>
|                         |<br>
+-------------------------+<br>

# Transaction Visualisation
As we know, a transaction is defined by those fields:
- hash
- list of inputs
- list of outputs

So a simple visualisation would be:
+-------------------------+<br>
| Transaction             |<br>
| [hash]                  |<br>
|-------------------------|<br>
| Inputs:                 |<br>
| [list of inputs]        |<br>
|-------------------------|<br>
| Outputs:                |<br>
| [list of outputs]       |<br>
+-------------------------+<br>
<br>
This visual representation would be inside the block representation<br>

