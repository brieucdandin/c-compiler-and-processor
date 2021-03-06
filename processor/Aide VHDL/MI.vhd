----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:08:46 05/14/2019 
-- Design Name: 
-- Module Name:    MI - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity MI is
	generic(N : natural := 16);
	Port (
		ins_a : in std_logic_vector (N-1 downto 0);
		ins_di : out std_logic_vector (N*2-1 downto 0)
	);
end MI;

architecture Behavioral of MI is
	type Tabins is array (0 to N-1) of std_logic_vector(N*2-1 downto 0);
	Signal ins : Tabins;
begin
	ins_di <= ins(to_integer(unsigned(ins_a)));
end Behavioral;

