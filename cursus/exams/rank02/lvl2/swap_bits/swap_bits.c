unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	byte;

	byte = octet >> 4;
	byte = octet << 4 | byte;
	return (byte);
}
