defmodule Tune do
  def main(args) do
    args |> parse_args |> process
  end

  def process([infile, outfile]) do
    params = infile |>  Path.expand |> parse_defaults
  end

  defp parse_args(args) do
      {options, _, _} = OptionParser.parse!(args,
	switches: [infile: :string, outfile: :string]
      )
    options
  end
end
