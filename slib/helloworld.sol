contract TokenSwap {
    address public alice;
    address public bob;
    uint256 public avaxAmount;
    uint256 public usdcAmount;
    bool public aliceDeposited;
    bool public bobDeposited;
    uint256 public deadline;
    
    IERC20 public usdcToken;
    
    // Alice creates the swap offer
    constructor(address _bob, uint256 _usdcAmount, address _usdcToken) payable {
        alice = msg.sender;
        bob = _bob;
        avaxAmount = msg.value;  // Alice deposits AVAX
        usdcAmount = _usdcAmount;
        usdcToken = IERC20(_usdcToken);
        aliceDeposited = true;
        deadline = block.timestamp + 1 hours;  // 1 hour to complete
    }
    
    // Bob deposits his USDC to complete the swap
    function depositUSDC() public {
        require(msg.sender == bob, "Only Bob can deposit");
        require(block.timestamp < deadline, "Swap expired");
        
        usdcToken.transferFrom(bob, address(this), usdcAmount);
        bobDeposited = true;
        
        // Automatically execute the swap
        executeSwap();
    }
    
    // Execute the swap once both have deposited
    function executeSwap() private {
        require(aliceDeposited && bobDeposited, "Both must deposit");
        
        // Send AVAX to Bob
        payable(bob).transfer(avaxAmount);
        
        // Send USDC to Alice
        usdcToken.transfer(alice, usdcAmount);
    }
    
    // If Bob doesn't deposit before deadline, Alice gets her AVAX back
    function refund() public {
        require(block.timestamp >= deadline, "Deadline not reached");
        require(!bobDeposited, "Swap already completed");
        
        payable(alice).transfer(avaxAmount);
    }
}